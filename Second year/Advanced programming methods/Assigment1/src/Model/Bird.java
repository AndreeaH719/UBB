package Model;

public class Bird implements Animal{
    float weight;
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
}
