package Animal.Repo;

import Animal.Exceptions.CustomException;
import Animal.Model.Animal;

public interface AnimalRepoInter {
    void addAnimal(Animal a) throws CustomException;
    int getSize();
    Animal[] getAnimals();
    void removeAnimal(int poz) throws CustomException;
}
