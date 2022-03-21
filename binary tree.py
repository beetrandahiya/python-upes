class BinaryTree:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value

    def insert(self, value):
        if self.value:
            if value < self.value:
                if self.left is None:
                    self.left = BinaryTree(value)
                else:
                    self.left.insert(value)
            elif value > self.value:
                if self.right is None:
                    self.right = BinaryTree(value)
                else:
                    self.right.insert(value)
        else:
            self.value = value

    def InOrderTraversal(self, root):
        res=[]
        if root:
            res=self.InOrderTraversal(root.left)
            res.append(root.value)
            res=res+self.InOrderTraversal(root.right)
        return res

    def PreOrderTraversal(self, root):
        res=[]
        if root:
            res.append(root.value)
            res+=self.PreOrderTraversal(root.left)
            res=res+self.PreOrderTraversal(root.right)
        return res
    def PostOrderTraversal(self, root):
        res=[]
        if root:
            res=self.PostOrderTraversal(root.left)
            res=res+self.PostOrderTraversal(root.right)
            res.append(root.value)
        return res

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.value)
        if self.right:
            self.right.PrintTree()

root = BinaryTree(100)
root.insert(50)
root.insert(55)
root.insert(60)
root.insert(20)
root.insert(52)

'''

Tree would look like:

       100
       / \
      50
     /  \
    20  55
       /  \
      52  60


'''
root.PrintTree()
print(root.PostOrderTraversal(root))
