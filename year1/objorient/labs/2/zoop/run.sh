javac $(find . -name *.java) -d bin -cp ".:lib/*" -Xlint:all

if [[ "$@" ]]; then
  java -cp lib/*:bin $@
else
  echo "Please type in the name of the class you want to run"
fi