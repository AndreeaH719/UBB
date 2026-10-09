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

    public void addBird(float weight)
    {
        Animal a = new Bird(weight);
        this.repo.addAnimal(a);
    }
    public void addCow(float weight)
    {
        Animal a = new Cow(weight);
        this.repo.addAnimal(a);
    }
    public void addPig(float weight)
    {
        Animal a = new Pig(weight);
        this.repo.addAnimal(a);
    }

    public Animal[] filterAnimals()
    {
        Animal[] animalsFil = new Animal[repo.getSize()];
        int s = 0;
        for(int i =0; i < repo.getSize(); i++)
            if(repo.getAnimals()[i].getWeight() > 3)
                animalsFil[s++] = repo.getAnimals()[i];
        return animalsFil;
    }

    public Animal[] getAll()
    {
        return repo.getAnimals();
    }

    public void remove(float weight)
    {
        repo.removeAnimal(weight);
    }

    public int getSize()
    {
        return repo.getSize();
    }
}
