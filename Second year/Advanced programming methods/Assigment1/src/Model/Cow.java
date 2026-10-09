package Model;

public class Cow implements Animal{
    //String name;
    float weight;
    public Cow(float weight)
    {
        this.weight=weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
}
