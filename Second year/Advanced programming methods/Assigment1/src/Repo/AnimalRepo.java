package Repo;

import Model.Animal;

public class AnimalRepo {
    private Animal[] animals;
    private int size;
    public void addAnimal(Animal a)
    {
        animals[++size] = a;
    }
    public Animal[] getAnimals()
    {
        return animals;
    }
}
