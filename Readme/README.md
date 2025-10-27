
## I) How to center a text?

You can use HTML directly in the README

```markdown
<div align="center">

### MODULE 00 - Starting

</div>
```

**Result:**

<div align="center">

### MODULE 00 - Starting

</div>


## II) How to break line?

a) Two spaces at the end of a line

```marwdown
This is line one  
This is line two
```

**Result:**

This is line one  
This is line two

b) Two line breaks (paragraph break)

```marwdown
This is line one

This is line two
```

**Result:**

This is line one

This is line two

c) HTML `<br>` tag

```marwdown
This is line one<br>
This is line two
```

**Result:**

This is line one<br>
This is line two

d) If you don't use these methods:

```markdown
This is line one
This is line two
```

**Result:**

This is line one
This is line two

## III) How to add a link?

a) Add link to words:

`[name](link)`

```markdown
[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown)
```

**Result:**

[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown)

b) Add link with description:

`[name](link) - Description`

```markdown
[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown) - Wikipedia Page of Warkdown
```

**Result:**

[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown) - Wikipedia Page of Warkdown 

c) Create a variable for link if need to reuse

`[link_var]: link`

```markdown
[Markdown's Wikipedia 1][Markdown's Wikipedia]
[Markdown's Wikipedia 2][Markdown's Wikipedia]

[Markdown's Wikipedia]: https://fr.wikipedia.org/wiki/Markdown
```

**Result:**

[Markdown's Wikipedia 1][Markdown's Wikipedia]  
[Markdown's Wikipedia 2][Markdown's Wikipedia]

[Markdown's Wikipedia]: https://fr.wikipedia.org/wiki/Markdown