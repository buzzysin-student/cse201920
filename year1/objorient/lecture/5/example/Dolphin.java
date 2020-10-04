public class Dolphin extends Mammal{
    @Override
    public void makeNoise() {
        System.out.println("squeek click");
    }
    public void makeNoise(Mammal m) {
       m.makeNoiseDolphin(this);
    }
    @Override
    public void makeNoiseDog(Mammal m) {
        System.out.println("Dolphin interacting with dog");
    }
    @Override
    public void makeNoiseDolphin(Mammal m) {
        System.out.println("Dolphin interacting with dolphin");
    }
    @Override
    public void makeNoiseLion(Mammal m) {
        System.out.println("Dolphin interacting with lion");
    }
}
