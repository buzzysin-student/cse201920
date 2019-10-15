choose :: Bool -> a -> b -> (Either a b)
choose a x y = 
  if a then 
    Left x
  else 
    Right y