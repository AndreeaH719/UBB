package View;

import Controller.AnimalController;
import Model.Animal;

public class AnimalView {
    private AnimalController animalController;
    public AnimalView(AnimalController animalController)
    {
        this.animalController = animalController;
    }
    public void startMenu()
    {
        System.out.println("\n");
        System.out.println("Adding birds...");
        try{
            animalController.addBird(13);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addBird(0.5F);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        System.out.println("Adding cows...");
        try{
            animalController.addCow(81);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addCow(12);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("Adding pigs...");
        try{
            animalController.addPig(10.6F);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addPig(1);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n");
        System.out.println("All the animals:");
        Animal[] animals = animalController.getAll();
        for(int  i = 0; i < animalController.getSize(); i++)
            System.out.println(animals[i]);


        System.out.println("\n");
        System.out.println("All the animals with weight greater than 3: ");
        try {
            Animal[] animalsF = animalController.filterAnimals();
            for(int  i = 0; i < animalController.getSize(); i++)
                if(animalsF[i] != null) System.out.println(animalsF[i]);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        System.out.println("\n");
        System.out.println("Removing an animal: ");
        try{
            animalController.remove(1);
            for(int  i = 0; i < animalController.getSize(); i++)
                System.out.println(animals[i]);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
