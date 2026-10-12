package Animal;

import Animal.Controller.AnimalController;
import Animal.Repo.AnimalRepo;
import Animal.Repo.AnimalRepoInter;
import Animal.View.AnimalView;

public class Main {
    public void main()
    {
        AnimalRepoInter repo = new AnimalRepo();
        AnimalController contr = new AnimalController(repo);
        AnimalView view = new AnimalView(contr);
        view.startMenu();
    }
}
