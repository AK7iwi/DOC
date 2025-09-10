
I) To center text, can use HTML directly in the README:

```markdown
<div align="center">

## MODULE 00 - Starting

</div>

```

II) Add a link

a) Add link to words:

`[name](link)`

```markdown
[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown)
```

Result:
[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown)

b) Add link with description:

`[name](link) - Description`

```markdown
[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown) - Wikipedia Page of Warkdown
```

Result:

[Markdown's Wikipedia](https://fr.wikipedia.org/wiki/Markdown) - Wikipedia Page of Warkdown 

c) Create a var for link if need to reuse

[link_name]: link

```markdown

[Markdown's Wikipedia 1][Markdown's Wikipedia]
[Markdown's Wikipedia 2][Markdown's Wikipedia]

[Markdown's Wikipedia]: https://fr.wikipedia.org/wiki/Markdown
```

Result:

[Markdown's Wikipedia 1][Markdown's Wikipedia]
[Markdown's Wikipedia 2][Markdown's Wikipedia]

[Markdown's Wikipedia]: https://fr.wikipedia.org/wiki/Markdown