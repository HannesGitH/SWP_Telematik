.extern BSP_LED_Toggle

.global attack_tzen

attack_tzen:
	bl lr
/*
attack_tzen:
    bx attack_veneer

attack_veneer:
	push {r0}
	ldr r0, [pc, #8]
	mov r12, r0
	pop {r0}
	bx r12

attack:
	sg
	b.w
*/

/* The idea for this file is to imitate a NonSecure callable function. The code above follows a function
 called SECURE_LEDToggle_veneer and SECURE_LEDToggle. As far as I understand that attack we must actually
 assume that the function is in a designated area already available, which means to sucessfully pull off
 this idea in real life the software on the board must be corrupted which is not easy as there is a veri-
 fication taking place before the actual download.
 Once the code is embedded, the remote attacker needs to get access to this code or let it be executed
 wtihin the downloaded code.*/
