public class Runner {
    public static void main (String [] args){
        Mammal mDolphin = new Dolphin();
        Mammal mDog = new Dog();
        Mammal mLion = new Lion();

        mDolphin.makeNoise();
        mDog.makeNoise();
        mLion.makeNoise();

        mDolphin.makeNoise(mDolphin);
        mLion.makeNoise(mDog);
        mDog.makeNoise(mLion);

    }
}
