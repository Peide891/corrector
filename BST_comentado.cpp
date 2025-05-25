//*********************************************************
// Mètodes privats auxiliars
//*********************************************************
template <typename T>
void BST<T>::clear(Item *node)
/* Pre: cert */
/* Post: Allibera tota la memòria dels nodes a partir de 'node',
   eliminant recursivament els fills esquerre i dret. */
{
    // H.I.: clear(node) elimina tots els nodes del subarbre amb arrel 'node'.
    // Fita: nombre de nodes restants a eliminar (altura del subarbre node).
    // Quan node == nullptr, ja no queda res per eliminar → finalització.
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

//*********************************************************
/* Pre: cert */
/* Post: Insereix 'd' al subarbre arrelat a 'node', mantenint l’ordre BST.
   Si ja hi és, no es fa res (no es permeten duplicats). */
template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d)
{
    // H.I.: insert(node, d) insereix d correctament en el subarbre arrelat a node,
    //       mantenint la propietat BST (tots els nodes a l'esquerra < node < dreta).
    // Fita: altura del subarbre node. Disminueix a cada crida recursiva.
    //       Quan node == nullptr → cas base → s'insereix nou node i s’acaba.

    if (node == nullptr) { // cas base: arbre buit
        node = new Item(d, nullptr, nullptr);
    }
    else if (node->data.getPar() > d.getPar()) { // d < node->data → anar esquerra
        node->left = insert(node->left, d);
    }
    else if (node->data.getPar() < d.getPar()) { // d > node->data → anar dreta
        node->right = insert(node->right, d);
    }
    // Si d == node->data, no es fa res (no es permeten duplicats)
    return node;
}

//*********************************************************
/* Pre: cert */
/* Post: Retorna el punter al node del subarbre arrelat a 'node'
   amb valor igual a 'd', o nullptr si no hi és. */
template <typename T>
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const
{
    // H.I.: find(node, d) cerca correctament d en el subarbre arrelat a node,
    //       seguint la propietat BST (si d < node → esquerra, si d > node → dreta).
    // Fita: altura del subarbre node. Disminueix a cada crida recursiva.
    //       Quan node == nullptr o node->data == d → cas base → s'acaba.

    Item* res = nullptr;
    if (node == nullptr or node->data.getPar() == d.getPar()) {
        res = node;
    }
    else {
        if (node->data.getPar() < d.getPar()) {
            res = find(node->right, d); // anar a la dreta
        }
        else {
            res = find(node->left, d); // anar a l’esquerra
        }
    }
    return res;
}

//*********************************************************
// Constructors
//*********************************************************
template <typename T>
BST<T>::BST()
/* Pre: cert */
/* Post: Crea un arbre buit (root = nullptr). */
{
    root = nullptr;
}

//*********************************************************
// Destructor
//*********************************************************
template <typename T>
BST<T>::~BST()
/* Pre: cert */
/* Post: Allibera tota la memòria de l’arbre. */
{
    clear(root);
}

//*********************************************************
// Modificadors
//*********************************************************
template <typename T>
void BST<T>::insert(const T& d)
/* Pre: cert */
/* Post: Insereix l’element d a l’arbre, si no hi és ja. */
{
    root = insert(root, d);
}

//*********************************************************
// Consultors
//*********************************************************
template <typename T>
pair<bool, T> BST<T>::find(const T& d) const
/* Pre: cert */
/* Post: Retorna (true, x) si x==d és a l’arbre, (false, d) si no. */
{
    pair<bool, T> res = make_pair(false, d);
    Item* node = find(root, d);
    if (node != NULL) {
        res.first = true;
        res.second = node->data;
    }
    return res;
}
