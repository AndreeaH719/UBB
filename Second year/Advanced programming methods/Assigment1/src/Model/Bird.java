package Model;

public class Bird implements Animal{
    float weight;
    String name;
    public Bird(String name, float weight)
    {
        this.name = name;
        this.weight = weight;
    }
    @Override
    public float getWeight()
    {
            return weight;
    }
}
