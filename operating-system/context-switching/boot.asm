%include "init.inc"

[org 0]
	jmp	07C0h:start

start:
	mov	ax, cx
	mov	ds, ax
	mov	es, ax

	mov	ax, 0xB800
	mov 	es, ax
	mov	di, 0
	mov	ax, word [msgBack]
	mov 	cx, 0x7FF

paint:
	mov	wor [es:di], ax
	add	di, 2
	dec	cx
	jnz	paint

read:
	
