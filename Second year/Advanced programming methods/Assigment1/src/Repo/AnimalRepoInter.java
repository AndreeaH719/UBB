package Repo;

import Model.Animal;

public interface AnimalRepoInter {
    void addAnimal(Animal a) throws Exception;
    int getSize();
    Animal[] getAnimals();
    void removeAnimal(float weight) throws Exception;
}
