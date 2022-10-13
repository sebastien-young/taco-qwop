/* based upon LittleJS Platformer Example */

'use strict';

const BodySize = vec (4,2);
const BodyIndex = 0;

class Body extends EngineObject {
	constructor (pos) {
		super (pos, BodySize, BodyIndex);
	}
}

class Leg extends EngineObject {
	constructor (pos, back=0) {
		super (pos, LegSize, LegIndex *(back+1));
	}
}

const TacoSize = vec (5,3);
const Front = vec (-2,1);
const Back = vec (-5,1);

class Taco extends EngineObject {
	constructor (pos) {
		super (pos, TacoSize);

		this.children += [
			this.body = new Body (pos-TacoSize.x),
			this.legs = [
				new Leg (pos-Front), /* front left */
				new Leg (pos-Front), /* front right */
				new Leg (pos-Back,1), /* back left */
				new Leg (pos-Back,1) /* back right */
			]
		];
	}
}
