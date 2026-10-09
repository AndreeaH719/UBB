package Model;

public class Pig implements Animal{
    float weight;
    String name;
    public Pig(String name, float weight)
    {
        this.name = name;
        this.weight=weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
}
