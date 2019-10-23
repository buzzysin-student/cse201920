-- * Continuing from lecture 6

data List a = Empty | Add a (List a)
  deriving Show

-- * Lists can be defined in many ways
case1 = Add 5 (Add 4 (Add 3 (Add 2 (Add 1 Empty))))
case2 = 5:(4:(3:(2:(1:[]))))
case3 = 5:4:3:2:1:[]
case4 = [5,4,3,2,1]

-- * A list can be empty
list1 :: [a]
list1 = [] 

-- * A list can contain elements of the same type
list2 :: [Int]
list2 = [1,2,3]

-- * A list can contain other lists
list3 :: [[a]]
list3 = [[], [], []]

-- * Performing operations on members

-- ? Checks if the list is empty
isEmpty :: [a] -> Bool
isEmpty [] = True
isEmpty _  = False

-- ? Checks if list has exactly one member
isSingle :: [a] -> Bool
isSingle []   = False
isSingle [x]  = True
isSingle _    = False

-- * Retreiving elements from a list

-- ? Get the first element of a list
head' :: [a] -> a
  -- ! This is a partial function (not defined for all input)!
head' []      = undefined 
  -- ? x is the first item from the list
head' (x:xs)  = x

-- ? Get the remainder of a list (everything except the head)
tail' :: [a] -> [a]
tail' (x:[])  = undefined
tail' (x:xs)  = xs

-- ? Get the length of a list
length' :: [a] -> Int
length' []     = 0
length' (x:xs) = 1 + length' xs

append :: [a] -> [a] -> [a]
append [] ys      = ys
append (x:xs) ys  = x : append xs ys