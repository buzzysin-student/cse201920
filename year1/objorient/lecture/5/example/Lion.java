public class Lion extends Mammal {
    @Override
    public void makeNoise() {
        System.out.println("roar");
    }
    public void makeNoise(Mammal m){
        m.makeNoiseLion(this);
    }
    @Override
    public void makeNoiseDog(Mammal m) {
        System.out.println("Lion interacting with dog");
    }
    @Override
    public void makeNoiseDolphin(Mammal m) {
        System.out.println("Lion interacting with dolphin");
    }
    @Override
    public void makeNoiseLion(Mammal m) {
        System.out.println("Lion interacting with lion");
    }
}
