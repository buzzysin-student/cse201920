class Pretty a where
  pretty :: a -> String

data Reaction = 
  Happy | Sad | Excited | 
  Angry | Indifferent

instance Pretty Reaction where 
  pretty Happy = ":)"
  pretty Sad = ":("
  pretty Excited = ":D"
  pretty Angry = ">:("
  pretty Indifferent = "|-|"