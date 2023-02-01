# CPcode

```flow
st=>start: Begin
op=>operation: Request Connection
cond=>condition: Successful?
e=>end: :)

st->op->cond
cond(yes)->e
cond(no)->op
```
