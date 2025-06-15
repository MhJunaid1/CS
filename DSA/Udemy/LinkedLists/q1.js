class LinkedList
{
    constructor(value)
    {
        this.head = {
            value : value,
            next : null
        }
        this.tail = this.head;
        this.length = 1;
    }
    Append(value)
    {
        let newObj = {
            value : value,
            next : null
        }
        this.head.next = newObj;
        this.tail = newObj;
    }
}