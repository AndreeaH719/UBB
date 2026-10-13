package Animal.Repo;

import Animal.Exceptions.CustomException;
import Animal.Model.Animal;

public class AnimalRepo implements AnimalRepoInter {
    private Animal[] animals;
    private int size;
    public AnimalRepo()
    {
        animals = new Animal[12];
        size =0;
    }
    @Override
    public void addAnimal(Animal a) throws CustomException
    {
        if(size >= animals.length)
            throw new CustomException("Repo is full");
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
    public void removeAnimal(int poz) throws CustomException
    {
        if(poz < 0 || poz >= size)
            throw new CustomException("The position is invalid");
        for(int j = poz; j < size - 1; j++)
            animals[j] = animals[j+1];
        size--;


    }
}
