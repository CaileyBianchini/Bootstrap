#version 410

in vec4 fPosition;
in vec4 fNormal;
in vec4 fColor;
in vec2 fTexCoord;

uniform vec3 kAmbient;
uniform vec3 kDiffuse;
uniform vec3 kSpecular;
uniform float kSpecularPower;

uniform vec3 iDirection0;
uniform vec3 iAmbient0;
uniform vec3 iDiffuse0;
uniform vec3 iSpecular0;

uniform vec3 iDirection1;
uniform vec3 iAmbient1;
uniform vec3 iDiffuse1;
uniform vec3 iSpecular1;

uniform vec3 cameraPosition;
uniform sampler2D difuseTexture;

out vec4 pColor;


void main() {

	vec3 kNormal = normalize(fNormal.xyz);
	vec3 iNormal0 = normalize(iDirection0);
	vec3 iNormal1 = normalize(iDirection1);

	// L I G H T  O N E //

	//Calculate ambient color
	vec3 ambientColor0 = (fColor.xyz + kAmbient) * iAmbient0;

	//Calculate diffuse color
	float lambertTerm0 = dot(kNormal, -iNormal0);
	lambertTerm0 = max(0.0f, min(1.0f, lambertTerm0));
	vec3 diffuseColor0 = (fColor.xyz + kDiffuse) * iDiffuse0 * lambertTerm0;

	//Calculate specular color
	vec3 surfaceToView0 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal0 = reflect(iNormal0, kNormal);
	float specularTerm0 = dot(surfaceToView0, reflectionNormal0);
	specularTerm0 = max(0.0f, specularTerm0);
	specularTerm0 = pow(specularTerm0, kSpecularPower);
	vec3 specularColor0 = (fColor.xyz + kSpecular) * iSpecular0 * specularTerm0;


	vec4 colorZero = vec4(ambientColor0 + diffuseColor0 + specularColor0, 1.0f);

	// L I G H T  T w o //

	//Calculate ambient color
	vec3 ambientColor1 = (fColor.xyz + kAmbient) * iAmbient1;

	//Calculate diffuse color
	float lambertTerm1 = dot(kNormal, -iNormal1);
	lambertTerm1 = max(0.0f, min(1.0f, lambertTerm1));
	vec3 diffuseColor1 = (fColor.xyz + kDiffuse) * iDiffuse1 * lambertTerm1;

	//Calculate specular color
	vec3 surfaceToView1 = normalize(cameraPosition - fPosition.xyz);
	vec3 reflectionNormal1 = reflect(iNormal1, kNormal);
	float specularTerm1 = dot(surfaceToView1, reflectionNormal1);
	specularTerm1 = max(0.0f, specularTerm1);
	specularTerm1 = pow(specularTerm1, kSpecularPower);
	vec3 specularColor1 = (fColor.xyz + kSpecular) * iSpecular1 * specularTerm1;


	vec4 colorOne = vec4(ambientColor1 + diffuseColor1 + specularColor1, 1.0f);

	// p C o l o r  M a t h //
	vec4 texColor = fColor * texture(difuseTexture, fTexCoord);

	pColor = texColor + colorZero + colorOne;


	// S N O W //
	//vec4 red = { 1.0f, 0.0f, 0.0f, 1.0f };
	////snow
	//if (kNormal.y >= 0.5f) {
	//	pColor = red;
	//}
	//if (pColor.g < 0.5f) {
	//	pColor = red;
	//}
}
