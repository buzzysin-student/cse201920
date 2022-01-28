import numpy as np
from numpy import array as array
from numpy import exp as exp
from numpy import log as log
from numpy.linalg import inv as inv
from numpy.linalg import det as det

# Laurence's Part

def norm(m, s2):
    return lambda x: 1/np.sqrt((2*np.pi)*s2) * exp(-0.5 * (x-m)**2/s2)

def mv_norm(m, C):
    return lambda x: 1/np.sqrt((2*np.pi)**len(x)*det(C)) * exp(-0.5 * (x-m).T @ inv(C) @ (x-m))

def feature(x, fs):
    return np.concatenate(list(f(x) for f in fs), axis=1)

def bias(fs, x, y):
    xe = feature(x, fs)
    return inv(xe.T @ xe) @ xe.T @ y

def sq_error(fs, x, y):
    xe = feature(x, fs)
    w = bias(fs, x, y)
    return np.sum(np.square(y - xe@w))

def m_sq_error(fs, x, y):
    return sq_error(fs, x, y)/len(x)

def polynomial(*coeffs):
    return list(map(lambda i,c: (lambda x: c* x**i),*zip(*enumerate(coeffs))))

def prob(logit):
    return 1/(1+exp(-logit))

def lprob(cls, logit):
    return log(prob(logit) if cls == 1 else 1 - prob(logit))

def lprobmodel(fn, cls0, cls1):
    sum0 = np.sum(lprob(0, fn(cls0)))
    sum1 = np.sum(lprob(1, fn(cls1)))
    return np.sum((sum0, sum1))

def softmax(logit):
    return exp(logit)/np.sum(exp(logit))

def p_norm(p):
    if p == np.Inf:
        return lambda x,y: np.max(np.abs(x - y))
    
    return lambda x,y: (np.sum(np.abs(x - y)**p))**(1/p)


def k_nearest(k, dist, p, cls0, cls1):
    distP = lambda x: dist(p, x)
    d0s = array(list(map(distP, cls0))).reshape((len(cls0),1))
    d1s = array(list(map(distP, cls1))).reshape((len(cls1),1))

    cls0d = np.concatenate([cls0, np.zeros((len(cls0),1)), d0s], axis=1)
    cls1d = np.concatenate([cls1, np.ones((len(cls0),1)), d1s], axis=1)

    clsds = np.concatenate([cls0d, cls1d])
    clsds = clsds[clsds[:,-1].argsort()][:k]

    print(clsds)

    clss, counts = np.unique(clsds[:,-2], return_counts=True)
    index = np.argmax(counts)
    nearest_cls = clss[index]
    
    return nearest_cls

def k_nearest_weighted(k, b, dist, p, cls0, cls1):
    distP = lambda x: dist(p, x)
    kernel = lambda x: exp(-distP(x)/(2*b))

    w0s = array(list(map(kernel, cls0))).reshape((len(cls0),1))
    w1s = array(list(map(kernel, cls1))).reshape((len(cls1),1))
    wsum = np.sum((np.sum(w0s), np.sum(w1s)), axis=None)

    w0avg = np.sum(w0s)/wsum
    w1avg = np.sum(w1s)/wsum

    return 0. if w0avg > w1avg else 1.

def bayes_inf(p, cls0, cls1):
    mu0 = np.mean(cls0)
    mu1 = np.mean(cls1)

    s20 = np.mean(cls0 ** 2) - (mu0** 2)
    s21 = np.mean(cls1 ** 2) - (mu1 ** 2)

    return 0. if norm(mu0, s20)(p) > norm(mu1, s21)(p) else 1.


# Majid's Part

def reverse(h):
    return array(list(h[len(h)-i-1] for i in range(len(h))))

def convolute(h, f):
    p = len(h)//2
    h2 = h[p:] + h[:p]
    fe = [0 for i in range(p)] + f + [0 for i in range(p)]
    result = [0 for i in fe]
    
    for x in range(len(f)):
        for m in range(-p, p+1):
            result[x + p] += h2[m] * fe[x + p - m]
            
    return result

def correlate(h, f):
    p = len(h)//2
    h2 = h[p:] + h[:p]
    fe = [0 for i in range(p)] + f + [0 for i in range(p)]
    result = [0 for i in fe]
    
    for x in range(len(f)):
        for m in range(-p, p+1):
            result[x + p] += h2[m] * fe[x + p + m] * (n if n else 1)
            
    return result
    
    
    
