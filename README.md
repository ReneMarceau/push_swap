# Push_swap

## Useful links

- [Subject PDF](https://cdn.intra.42.fr/pdf/pdf/66937/fr.subject.pdf)
- [Push_Swap by Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Pushswap Epitech Project](https://sharkigamers.github.io/pushswap_epitech_project/)
- [Push_Swap by Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push_Swap by Leo Fu](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Push_Swap by AdrianWR](https://github.com/AdrianWR/push_swap)
- [Push_Swap by anyaschukin](https://github.com/anyaschukin/Push_Swap)
- [Stackoverflow](https://stackoverflow.com/questions/75100698/what-is-the-most-efficient-way-to-sort-a-stack-using-a-limited-set-of-instructio)
- [Youtube video](https://www.youtube.com/watch?v=7KW59UO55TQ)

## Étapes

- Parsing de l'entrée standard et mettre les nombres dans la Stack A (doubly-circular linked list)

- Comprendre comment accéder aux valeurs dans la "doubly-circular linked list"

- Check si il n'y a aucune erreur détecter dans la Stack A

- Check si la Stack A est déja rangée. Si oui le programme s'arrête sans rien faire

- Faire les différents algorithmes pour la stack A < 6
- Faire l'algorithme pour la Stack A < 100
- Faire l'algorithme pour la Stack A < 500

## Choses à faire

- [ ] Faire une recherche sur Insertion Sort
- [ ] Faire une recherche sur Radix sort
- [x] Parsing avec arguments entre "" et sans. Ex:"1 2 3 ..." et 1 2 3 ...
- [x] Parsing même si trop d'espaces: "1 2          3" ou 1 2       3
- [x] Vérifier si tous les arguments sont des nombres entier
- [x] Vérifier qu'il n'y a aucun doublon
- [x] Vérifier que les arguments ne soient pas déjà rangés si oui ne rien faire
- [x] À corriger: Programme ne rentre pas les informations après un 0 (À cause de count arg qui arrête de compter dès qu'il voit un 0)
- [x] Créer les fonctions pour libérer la mémoire
- [x] Créer les fonctions pour push dans les différentes stacks
- [ ] Créer les fonctions pour swap les stacks
- [ ] Créer les fonctions pour rotate les stacks
- [ ] Créer les fonctions pour reverse rotate les stacks


### To check leaks

leaks --atExit -- ./push_swap ""
