let tree = new BST(null);

function setup() {
  createCanvas(800, 600);
  background(63, 63, 63);
  for (let i = 0; i < 10; i++)
    tree.add(floor(random(0, 50)));
}

function draw() {
  background(63, 63, 63);
  // draws the tree
  tree.traversing();
}