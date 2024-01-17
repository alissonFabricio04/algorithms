export class QuickFind {
  private ids: Array<number> = []

  constructor(length: number) {
    for (let i = 0; i < length; i++) {
      this.ids[i] = i
    }
  }

  public union(p: number, q: number): void {
    const pid = this.ids[p]
    const qid = this.ids[q]
  
    for (let i = 0; i < this.ids.length; i++)
    {
      if (this.ids[i] === pid) {
        this.ids[i] = qid;
      }
    }
  }

  public connected(p: number, q: number): boolean {
    return this.ids[p] === this.ids[q]
  }

  public find(p: number): number {
    return this.ids[p] ?? -1 
  }

  public count(): number {
    const components: Array<number> = []
    for (let i = 0; i < this.ids.length; i++) {
      const currentId = this.ids[i]
      if(!components.includes(currentId)) {
        components.push(currentId)
      }
    }
    return components.length
  }
}

export function executeQuickFind() {
  const N = 8
  const quickFind = new QuickFind(N)
  const input = [
    [1, 4],
    [4, 5],
    [2, 3],
    [2, 6],
    [3, 7],
    [6, 3]
  ]
  
  for (let i = 0; i < input.length; i++) {
    const currentUnion = input[i]
    quickFind.union(currentUnion[0], currentUnion[1])
  }

  console.log(`The quantity of components in the Union is ${quickFind.count()}`)
}