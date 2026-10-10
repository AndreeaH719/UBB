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
        /*
        try {
            System.out.println("Adding birds...");
            animalController.addBird(3);
            animalController.addBird(4.5F);
            animalController.addBird(2);

            try{
                animalController.addBird(-5);
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }

            System.out.println("Adding cows...");
            animalController.addCow(23);
            animalController.addCow(50.6F);
            animalController.addCow(0.5F);
            //animalController.addCow(0.5F);
           // animalController.addCow(0.5F);

            System.out.println("Adding pigs...");
            animalController.addPig(-1);
            animalController.addPig(37.9F);
           animalController.addPig(49.2F);
           // animalController.addPig(49.2F);

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }*/

        System.out.println("Adding birds...");
        try{
            animalController.addBird(1);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addBird(30.5F);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        System.out.println("Adding cows...");
        try{
            animalController.addCow(48);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addCow(81);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("Adding pigs...");
        try{
            animalController.addPig(0.6F);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        try{
            animalController.addPig(21);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        System.out.println("\n");
        System.out.println("All the animals:");
        Animal[] animals = animalController.getAll();
        for(int  i = 0; i < animalController.getSize(); i++)
            System.out.println(animals[i].toString());


        System.out.println("\n");
        System.out.println("All the animals with weight grater than 3: ");
        try {
            Animal[] animalsF = animalController.filterAnimals();
            for(int  i = 0; i < animalController.getSize(); i++)
                if(animalsF[i] != null) System.out.println(animalsF[i].toString());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }


        System.out.println("\n");
        System.out.println("Removing an animal: ");
        try{
            animalController.remove(1);
            for(int  i = 0; i < animalController.getSize(); i++)
                System.out.println(animals[i].toString());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
