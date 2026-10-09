package Model;

public class Pig implements Animal{
    float weight;
   // String name;
    public Pig(float weight)
    {
        this.weight=weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
}
