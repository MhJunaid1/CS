class HashTable {
    constructor(size){
        this.data = new Array(size);
    }
    set(key, value)
    {
        let hashIndex = this._hash(key);
        this.data[hashIndex]=value;
    }
    get(key)
    {
        return this.data[this._hash(key)];
    }
    _hash(key) {
        let hash = 0;
        for ( let i=0; i<key.length; i++) {
            hash = (hash + key.charCodeAt(i))% this.data.length;
        }
        return hash;
    }
}
const myHashTable = new HashTable(50);
myHashTable.set('grapes', 10000);
myHashTable.get('grapes');