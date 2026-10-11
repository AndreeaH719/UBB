package Repo;

import Model.Animal;

public class AnimalRepo implements AnimalRepoInter{
    private Animal[] animals;
    private int size;
    public AnimalRepo()
    {
        animals = new Animal[13];
        size =0;
    }
    @Override
    public void addAnimal(Animal a) throws Exception
    {
        if(size == animals.length)
            throw new Exception("Repo is full");
        animals[size++] = a;
    }
    @Override
    public Animal[] getAnimals()
    {
        return animals;
    }
    @Override
    public int getSize()
    {
        return size;
    }
    @Override
    public void removeAnimal(float weight) throws Exception
    {
        if(weight <= 0)
            throw new Exception("The weight must be > 0");
        int old_size = size;
        for(int i = 0; i < size; i++)
            if(animals[i].getWeight() == weight)
            {
                for(int j = i; j < size - 1; j++)
                    animals[j] = animals[j+1];
                size--;
                //return;
            }
        if(old_size == size) throw new Exception("Animal not found");
    }
}
