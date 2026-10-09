package Model;

public class Cow implements Animal{
    String name;
    float weight;
    public Cow(String name, float weight)
    {
        this.name=name;
        this.weight=weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
}
