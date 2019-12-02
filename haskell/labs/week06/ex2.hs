class Pretty a where
  pretty :: a -> String

data Reaction = 
  Happy | Sad | Excited | 
  Angry | Indifferent

instance Pretty Reaction where 
  pretty Happy = ":)"
  pretty Sad = ":("
  pretty Excit\ed = ":D"
  pretty Angry = ">:("
  pretty Indifferent = "|-|"