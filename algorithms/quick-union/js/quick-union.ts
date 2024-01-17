export class QuickUnion {
  private parent: Array<number>

  constructor(N: number) {
    this.parent = []
    for (let i = 0; i < N; i++) {
      this.parent.push(i)
    }
  }

  private findRoot(e: number): number {
    while(e !== this.parent[e]) {
      e = this.parent[e]
    }
    return e
  }

  public union(p: number, q: number): void {
    const rootP = this.findRoot(p)
    const rootQ = this.findRoot(q)
    this.parent[rootP] = rootQ
  }

  public connected(p: number, q: number): boolean {
    return this.findRoot(p) === this.findRoot(q)
  }

  public count() {
    const roots: Array<number> = []
    for (let i = 0; i < this.parent.length; i++) {
      const rootI = this.findRoot(i)
      if(!roots.includes(rootI)) {
        roots.push(rootI)
      }
    }
    return roots.length
  }
}

export function executeQuickUnion() {
  const N = 7
  const quickUnion = new QuickUnion(N)
  const input = [
    [2, 5],
    [4, 5],
    [3, 2],
  ]
  
  for (let i = 0; i < input.length; i++) {
    const currentUnion = input[i]
    quickUnion.union(currentUnion[0], currentUnion[1])
  }

  console.log(`The quantity of components in the Union is ${quickUnion.count()}`)
}
