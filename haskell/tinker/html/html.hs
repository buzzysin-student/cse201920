cnewline = "\n"
ctabchar = "\t"
cnewbrek = cnewbrek ++ cnewline

tag t cnt = "<"++t++">" ++ cnewbrek ++ cnt ++ cnewline ++ "</"++t++">"

main = do
  putStrLn tag "html" (
      tag "head" (
        tag "meta" ""
      )
    )