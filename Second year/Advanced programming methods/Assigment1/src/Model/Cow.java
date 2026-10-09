package Model;

public class Cow implements Animal{
    //String name;
    private float weight;
    public Cow(float weight)
    {
        this.weight=weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
    @Override
    public String toString()
    {
        return "Cow with " + weight + " kg";
    }
}
