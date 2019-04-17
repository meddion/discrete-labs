let coords = [];
class BST {
  constructor(node) {
    this.root = node;
    this.size = 0;
  }

  // adds a node to the tree
  add(value) {
    this.size++;
    if (this.root == null) {
      coords.push([width * 0.5, 50]);
      this.root = new Node(value, coords[0][0], coords[0][1]);
    } else {
      this.root.addNode(new Node(value));
    }
  }

  containts(value) {
    return this.size == 0 ? false : this.root.containts(value);
  }

  delete(value) {
    const removeNode = function(node, value) {
      if (node == null)
        return null;

      if (node.value == value) {
        // #1 node has no children
        if (node.leftNode == null && node.rightNode == null)
          return null;

        // #2 node has only one child
        if (node.leftNode == null)
          return node.rightNode;

        if (node.rightNode == null)
          return node.leftNode;

        // #3 node has two children
        let tempNode = node.rightNode;
        while (tempNode.leftNode !== null)
          tempNode = tempNode.leftNode;

        node.value = tempNode.value;
        node.rightNode = removeNode(node.rightNode, tempNode.value);
        return node;
      } else if (node.value > value) {
        node.leftNode = removeNode(node.leftNode, value);
        return node;
      } else {
        node.rightNode = removeNode(node.rightNode, value);
        return node;
      }
    }
    this.root = removeNode(this.root, value);
  }

  // implements inorder traversing
  traversing() {
    if (this.root != null)
      this.root.visitInOrder(this.root);
  }
}