package Controller;

import Model.Animal;
import Model.Bird;
import Model.Cow;
import Model.Pig;
import Repo.AnimalRepo;
import Repo.AnimalRepoInter;

public class AnimalController {
    private AnimalRepoInter repo;
    public AnimalController(AnimalRepoInter repo)
    {
        this.repo=repo;
    }

    public void addBird(float weight) throws Exception
    {
        if(weight <= 0)
            throw new Exception("The weight must be > 0");
        Animal a = new Bird(weight);
        this.repo.addAnimal(a);
    }
    public void addCow(float weight) throws Exception
    {
        if(weight <= 0)
            throw new Exception("The weight must be > 0");
        Animal a = new Cow(weight);
        this.repo.addAnimal(a);
    }
    public void addPig(float weight) throws Exception
    {
        if(weight <= 0)
            throw new Exception("The weight must be > 0");
        Animal a = new Pig(weight);
        this.repo.addAnimal(a);
    }

    public Animal[] filterAnimals() throws Exception
    {
        Animal[] animalsFil = new Animal[repo.getSize()];
        int s = 0;
        boolean found = false;
        for(int i =0; i < repo.getSize(); i++)
            if(repo.getAnimals()[i].getWeight() > 3)
            {
                animalsFil[s++] = repo.getAnimals()[i];
                found = true;
            }
        if(found == false)
            throw new Exception("There isn t an animal with this property");
        return animalsFil;
    }

    public Animal[] getAll()
    {
        return repo.getAnimals();
    }

    public void remove(float weight) throws Exception
    {
        repo.removeAnimal(weight);
    }

    public int getSize()
    {
        return repo.getSize();
    }
}
