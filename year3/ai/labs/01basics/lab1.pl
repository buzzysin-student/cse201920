%% Exercise 1.1

% vINCENT is an           ATOM
% Footmassage is a        VARIABLE (caps)
% variable23 is an        ATOM      
% Variabble2000 is a      VARIABLE (caps)
% big_kahuna_burger is an ATOM
% 'big_kahuna_burger' is  NEITHER
% big kahuna burger       NEITHER
% 'Jules'                 ATOM     (quotes)
% _Jules                  VARIABLE (underscore)
% '_Jules'                ATOM     (quotes)

%% Exercise 1.2

% loves(Vincent, mia)         COMPLEX (loves/2)
% 'loves(Vincent, mia)'       ATOM
% Butch(boxer)                NEITHER (functor is not an atom)
% boxer(Butch)                COMPLEX (boxer/1)
% and(big(burger), kahuna(burger))
%                             COMPLEX (and/2, big/1, kahuna/1)
% and(big(X), kahuna(X))
%                             COMPLEX (and/2, big/1, kahuna/1)
% _and(big(X), kahuna(X))     NEITHER (functor is not an atom)
% (Butch kills Vincent)       NEITHER (Operator?)
% kills(Butch Vincent)        NEITHER (comma omitted)
% kills(Butch, Vincent        NEITHER (closing parenthesis missing)

%% Exercise 1.3

%1 woman(vincent).                          
%2 woman(mia).                               
%3 man(jules).                               
%4 person(X)   :- man(X); woman(X).          
%5 loves(X,Y)  :- father(X,Y).              
%6 father(Y,Z) :- man(Y), son(Z,Y).        
%7 father(Y,Z) :- man(Y), daughter(Z,Y).

% Facts are 1, 2, 3
% Rules are 4, 5, 6, 7
% Predicates are all of them
% Rule heads are person/1, loves/2, father/2, father/2

%% Exercise 1.4

% Butch is a killer
killer(butch).

% Mia and Marcellus are married
married(marcellus, mia).
married(mia, marcellus).

% Zed is dead
dead(zed).

% Marcellus kills everyone who gives Mia a foot massage
kills(marcellus, X) :-
    foot_massages(mia, X).

% Mia loves everyone who is a good dancer
loves(mia, X) :-
    good_dancer(X).

% Jules eats anything that is nutritious or tasty 
eats(jules, X) :-
    (   nutritious(X)
    ;   tasty(X)
    ).

%% Exercise 1.5
wizard(ron).
has_wand(harry).
quidditch_player(harry).
wizard(X) :-
    has_broom(X),
    has_wand(X).
has_broom(X) :-
    quidditch_player(X).

% wizard(ron)       = true
% witch(ron)        = witch is undefined 
% wizard(hermione)  = false
% witch(hermione)   = witch is undefined
% wizard(harry)     = false
% wizard(Y)         = Y = ron ;
%                     Y = harrry .
% witch(Y)          = witch is undefined

%%%%%%%%%%%%%%
%% Remember %%
%%%%%%%%%%%%%% 

% clause(X) :- fact(X) ; rule(X).