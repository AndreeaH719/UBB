package Model;

public class Pig implements Animal{
    private float weight;
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
    @Override
    public String toString()
    {
        return "Pig with " + weight + " kg";
    }
}
