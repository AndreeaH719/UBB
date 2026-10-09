import Controller.AnimalController;
import Model.Animal;
import Repo.AnimalRepo;
import Repo.AnimalRepoInter;
import View.AnimalView;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void main() {
    AnimalRepo repo = new AnimalRepo();
    AnimalController contr = new AnimalController(repo);
    AnimalView view = new AnimalView(contr);
    view.startMenu();
}
