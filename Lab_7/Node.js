let r = 20;
let y = r * 4;
let x = r * 4;

class Node {
  constructor(value, x, y) {
    this.value = value;
    this.x = x;
    this.y = y;
    this.leftNode = null;
    this.rightNode = null;
  }

  addNode(newNode) {
    if (this.value > newNode.value) {
      if (this.leftNode == null) {
        // setting coords for visualization
        newNode.x = this.x - x;
        newNode.y = this.y + y;
        while (this.findIntersection(newNode)) newNode.y += y;
        coords.push([newNode.x, newNode.y]);

        this.leftNode = newNode;
      } else {
        this.leftNode.addNode(newNode);
      }
    } else if (this.value < newNode.value) {
      if (this.rightNode == null) {
        // setting coords for visualization
        newNode.x = this.x + x;
        newNode.y = this.y + y;
        while (this.findIntersection(newNode)) newNode.y += y;
        coords.push([newNode.x, newNode.y]);

        this.rightNode = newNode;
      } else {
        this.rightNode.addNode(newNode);
      }
    }
  }

  containts(value) {
    if (this.value == value)
      return true;
    else if (this.value > value)
      return this.leftNode == null ? false : this.leftNode.containts(value);
    else if (this.value < value)
      return this.rightNode == null ? false : this.rightNode.containts(value);
  }

  // visits nodes in order
  visitInOrder(parent) {
    if (this.leftNode != null)
      this.leftNode.visitInOrder(this);

    /* DRAWING BLOCK START */
    // line element
    let psi = Math.atan((parent.y - this.y) / (parent.x - this.x));
    let startX = parent.x + (r * Math.cos(psi));
    let startY = parent.y + (r * Math.sin(psi));
    strokeWeight(1);
    stroke(215, 247, 245);
    line(startX, startY, this.x, this.y);
    // circle element
    fill(215, 247, 245);
    circle(this.x, this.y, r * 2);
    // text element
    fill(63, 63, 63);
    textStyle(BOLD);
    textSize(r - this.value.toString().length * 1.5);
    textAlign(CENTER, CENTER);
    text(this.value, this.x, this.y);
    /* DRAWING BLOCK END */

    if (this.rightNode != null)
      this.rightNode.visitInOrder(this);
  }

  // visits nodes in pre-order way
  visitPreOrder() {
    console.log(this.value);

    if (this.leftNode != null)
      this.leftNode.visitPreOrder(this);

    if (this.rightNode != null)
      this.rightNode.visitPreOrder(this);
  }

  // visits nodes in post-order way (the root gets printed the last)
  visitPostOrder() {
    if (this.leftNode != null)
      this.leftNode.visitPostOrder(this);

    if (this.rightNode != null)
      this.rightNode.visitPostOrder(this);

    console.log(this.value);
  }

  findIntersection(newNode) {
    return coords.find(function(value) {
      return dist(value[0], value[1], newNode.x, newNode.y) < r * 2;
    });
  }
}