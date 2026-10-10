package Model;

public class Bird implements Animal{
    private float weight;
   // String name;
    public Bird(float weight)
    {
        this.weight = weight;
    }
    @Override
    public float getWeight()
    {
        return weight;
    }
    @Override
    public String toString()
    {
        return "Bird with " + weight + " kg";
    }
}
