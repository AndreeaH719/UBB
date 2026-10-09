package Repo;

import Model.Animal;

public class AnimalRepo implements AnimalRepoInter{
    private Animal[] animals;
    private int size;
    public AnimalRepo()
    {
        animals = new Animal[100];
        size =0;
    }
    @Override
    public void addAnimal(Animal a)
    {
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
    public void removeAnimal(float weight)
    {
        for(int i = 0; i < size; i++)
            if(animals[i].getWeight() == weight)
            {
                for(int j = i; j < size - 1; j++)
                    animals[j] = animals[j+1];
                size--;
                return;
            }

    }
}
