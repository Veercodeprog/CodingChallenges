stuct Treenode<T>{
    val: <T>,
    left: Option<Box<Treenode<T>>>,
    right: Option<Box<Treenode<T>>>,
}

impl <T> Treenode<T> {
    fn new(value: T) -> Treenode<T> {
        Treenode {
            val: value,
            left: None,
            right: None,
        }
    }
}
