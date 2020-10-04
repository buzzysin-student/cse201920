fromJusts :: [Maybe a] -> [a]
fromJusts [] = []
fromJusts (Just a :xs) = a : fromJusts xs
fromJusts (Nothing:xs) =     fromJusts xs