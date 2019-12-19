cnewline = "\n"
ctabchar = "\t"
cnewbrek = cnewbrek ++ cnewline

tag t cnt = "<"++t++">" ++ cnewbrek ++ t ++ cnewline ++ "</"++t++">"

main = do
  putStrLn tag "html" (
      tag "head" (
        tag "meta" ""
      )
    )