public class Dog extends Mammal {
    @Override
    public void makeNoise() {
        System.out.println("woof");
    }
    public void makeNoise(Mammal m){
        m.makeNoiseDog(this);
    }
    @Override
    public void makeNoiseDog(Mammal m) {
        System.out.println("Dog interacting with dog");
    }
    @Override
    public void makeNoiseDolphin(Mammal m) {
        System.out.println("Dog interacting with dolphin");
    }
    @Override
    public void makeNoiseLion(Mammal m) {
        System.out.println("Dog interacting with lion");
    }
}
