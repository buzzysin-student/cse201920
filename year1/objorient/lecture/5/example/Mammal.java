public abstract class Mammal {

    public void stateAttributes() {
        System.out.println("Warm blood, 3 inner ear bones and fur / hair");
    }

    public abstract void makeNoise();

    public abstract void makeNoise(Mammal m);

    public abstract void makeNoiseDog(Mammal m);

    public abstract void makeNoiseLion(Mammal m);

    public abstract void makeNoiseDolphin(Mammal m);

}
