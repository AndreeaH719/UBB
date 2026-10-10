import Controller.AnimalController;
import Model.Animal;
import Repo.AnimalRepo;
import Repo.AnimalRepoInter;
import View.AnimalView;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or

void main() {
    AnimalRepoInter repo = new AnimalRepo();
    AnimalController contr = new AnimalController(repo);
    AnimalView view = new AnimalView(contr);
    view.startMenu();
}
