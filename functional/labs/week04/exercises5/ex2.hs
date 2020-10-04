import Test.QuickCheck

check_repeat n x = 
  n >= 0 ==> length (take n (repeat x)) == n