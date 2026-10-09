package Repo;

import Model.Animal;

public interface AnimalRepoInter {
    void addAnimal(Animal a);
    int getSize();
    Animal[] getAnimals();
    void removeAnimal(float weight);
}
